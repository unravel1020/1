
#include "stdafx.h"
#include "disanfang.h"
#ifdef _MANAGED
#pragma managed(push, off)
#endif
#include<map>
#include<tuple>
#include<mutex>

#include <atlstr.h>

bool on;
bool jianbianON;
HMODULE hDLLRes;
std::atomic<bool> should_stop{ false };
std::atomic_bool exerunning{ true };
BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	hDLLRes = hModule;//得到资源实例
	return TRUE;
}

//utf8编码转gbk编码

std::string utf8_to_gbk(const std::string& utf8_str) {
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len];
	MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, wstr, len);

	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* gbk_str = new char[len];
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, gbk_str, len, NULL, NULL);

	std::string result(gbk_str);
	delete[] wstr; // 释放内存
	delete[] gbk_str;

	return result;
}

void do_session(tcp::socket&& socket) {
	try {
		// 创建websocket
		websocket::stream<tcp::socket> ws(std::move(socket));
		// 接受websocket握手

		ws.accept();
		std::cout << "网络连接成功！" << std::endl;
		std::thread t_read1([&ws]() {
			try {

				//接收按钮消息
				while (!should_stop)
				{
					Sleep(1);
					beast::flat_buffer buffer;
					ws.read(buffer);
					std::string message = beast::buffers_to_string(buffer.data());

					//如果数据包含中文，需要转为gbk编码，如果没有则不需要
					message = utf8_to_gbk(message);
					std::cout << message << std::endl;

					//收到消息
					 if (message == "return") {
					  
					  
					 }
					 rapidjson::Document doc;
					 doc.Parse(message.c_str());
					 if (doc.HasParseError()) {
						 std::cerr << "数据解析json失败！" << doc.GetParseError() << std::endl;
					 }
					 else {
						 const rapidjson::Value& obj = doc;
						//判断是否包含了你需要解析的数据
						 if (obj.HasMember("key")&& obj.HasMember("value")) {

							 //判断数据类型
							 if (obj["key"].IsString()&& obj["value"].IsString()) {
								 std::string key = obj["key"].GetString();
								 std::string value = obj["value"].GetString();
							 
								 if (key=="图书馆1")
								 {
									 jianbianON = 1;
								 }

								 if (key == "图书馆2")
								 {
									 jianbianON = 1;
								 }

								 if (key == "图书馆3") 
								 {
								 }
							 }
						 }

					 }

				}
			}

			catch (const std::exception& e) {
				should_stop = true;
			}
			});
		t_read1.join();

		ws.close(websocket::close_code::normal);
	}
	catch (const std::exception& e) {

	}
}

//画面亮度渐变线程
DWORD WINAPI jianbian(LPVOID _p)
{
	while (on)
	{
		DWORD _dwStatus;
		DWORD _dwInfo;
		//等待加载完毕
		W3DGetSystemStatus(&_dwStatus, &_dwInfo);
		if (_dwStatus == 1 && _dwInfo == 2)
		{
			break;
		}
		Sleep(10);
	}

	W3DSetTipShowTime(100);

	//开始工作
	while (on)
	{ 
		if (jianbianON)
		{
			static float _ph = 0.0;
			W3DSetRenderBrightness(abs(cos(_ph)));
			_ph += 0.1f;
			if (_ph > M_PI)
			{
				_ph = 0.0f;
				jianbianON = 0;
			}
		}

		Sleep(10);
	}
	return TRUE;
}


//入口
void W3DCustomEntry()
{
	jianbianON = 0;
	//开始工作
	on = 1;
	//主线程
	HANDLE _h = CreateThread(0, 0, jianbian, 0, 0, 0);
	CloseHandle(_h);

	//创建入口线程，需要detach运行，不然会卡住仿真
	std::thread t_client3([] {

		net::io_context ioc3;
		tcp::acceptor acceptor3(ioc3, { tcp::v4(), PORT_EXCHANGEDATA });
		std::cout << "前端控制插件运行" << std::endl;
		//为了断线重连，使用while循环
		while (exerunning) {
			Sleep(1);
			tcp::socket socket3(ioc3);
			acceptor3.accept(socket3);
			do_session(std::move(socket3));
		}
		});

	t_client3.detach();

	
}