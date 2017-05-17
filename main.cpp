#define WINVER 0x0500 
#include <string>
#include <Windows.h>
#include <iostream>


const DWORD SECOND_MILLI = 1000;


int main() {
	INPUT ip;
	
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0;
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;
	ip.ki.dwFlags = 0; //dwFlags is 0 for key press
	
	size_t amount; 
	DWORD TimesPerSecond; 
	std::string sMessage;

	std::cout << "Message To Spam: ";
	std::getline(std::cin, sMessage);
	std::cout << "\nNumber Of Messages To Spam: ";
	std::cin >> amount;
	std::cout << "\nNumber Of Messages To Spam Per Second: ";
	std::cin >> TimesPerSecond;
	
	sMessage.push_back(VK_RETURN); // appends 0x0D to the end of the string so enter is pressed at the end of the string
	
	Sleep(3000); //wait 3 seconds

	for (size_t x = 0; x < amount; x++) {
		for (size_t i = 0; i < sMessage.length(); i++) {
			ip.ki.wVk = VkKeyScan(sMessage[i]);
			SendInput(1, &ip, sizeof(INPUT));
			}

		/* Only works for TimesPerSecond > 10*/
		Sleep(SECOND_MILLI - (TimesPerSecond * 100));
		}
	
	char exit;
	std::cin >> exit;
	return 0;
	}
