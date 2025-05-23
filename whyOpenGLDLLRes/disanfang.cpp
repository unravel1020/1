
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
	hDLLRes = hModule;//�õ���Դʵ��
	return TRUE;
}

//utf8����תgbk����

std::string utf8_to_gbk(const std::string& utf8_str) {
	int len = MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, NULL, 0);
	wchar_t* wstr = new wchar_t[len];
	MultiByteToWideChar(CP_UTF8, 0, utf8_str.c_str(), -1, wstr, len);

	len = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);
	char* gbk_str = new char[len];
	WideCharToMultiByte(CP_ACP, 0, wstr, -1, gbk_str, len, NULL, NULL);

	std::string result(gbk_str);
	delete[] wstr; // �ͷ��ڴ�
	delete[] gbk_str;

	return result;
}

void do_session(tcp::socket&& socket) {
	try {
		// ����websocket
		websocket::stream<tcp::socket> ws(std::move(socket));
		// ����websocket����

		ws.accept();
		std::cout << "�������ӳɹ���" << std::endl;
		std::thread t_read1([&ws]() {
			try {

				//���հ�ť��Ϣ
				while (!should_stop)
				{
					Sleep(1);
					beast::flat_buffer buffer;
					ws.read(buffer);
					std::string message = beast::buffers_to_string(buffer.data());

					//������ݰ������ģ���ҪתΪgbk���룬���û������Ҫ
					message = utf8_to_gbk(message);
					std::cout << message << std::endl;

					//�յ���Ϣ
					 if (message == "return") {
					  
					  
					 }
					 rapidjson::Document doc;
					 doc.Parse(message.c_str());
					 if (doc.HasParseError()) {
						 std::cerr << "���ݽ���jsonʧ�ܣ�" << doc.GetParseError() << std::endl;
					 }
					 else {
						 const rapidjson::Value& obj = doc;
						//�ж��Ƿ����������Ҫ����������
						 if (obj.HasMember("key")&& obj.HasMember("value")) {

							 //�ж���������
							 if (obj["key"].IsString()&& obj["value"].IsString()) {
								 std::string key = obj["key"].GetString();
								 std::string value = obj["value"].GetString();
							 
								 if (key=="ͼ���1")
								 {
									 jianbianON = 1;
								 }

								 if (key == "ͼ���2")
								 {
									 jianbianON = 1;
								 }

								 if (key == "ͼ���3") 
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

//�������Ƚ����߳�
DWORD WINAPI jianbian(LPVOID _p)
{
	while (on)
	{
		DWORD _dwStatus;
		DWORD _dwInfo;
		//�ȴ��������
		W3DGetSystemStatus(&_dwStatus, &_dwInfo);
		if (_dwStatus == 1 && _dwInfo == 2)
		{
			break;
		}
		Sleep(10);
	}

	W3DSetTipShowTime(100);

	//��ʼ����
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


//���
void W3DCustomEntry()
{
	jianbianON = 0;
	//��ʼ����
	on = 1;
	//���߳�
	HANDLE _h = CreateThread(0, 0, jianbian, 0, 0, 0);
	CloseHandle(_h);

	//��������̣߳���Ҫdetach���У���Ȼ�Ῠס����
	std::thread t_client3([] {

		net::io_context ioc3;
		tcp::acceptor acceptor3(ioc3, { tcp::v4(), PORT_EXCHANGEDATA });
		std::cout << "ǰ�˿��Ʋ������" << std::endl;
		//Ϊ�˶���������ʹ��whileѭ��
		while (exerunning) {
			Sleep(1);
			tcp::socket socket3(ioc3);
			acceptor3.accept(socket3);
			do_session(std::move(socket3));
		}
		});

	t_client3.detach();

	
}