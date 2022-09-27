#include <iostream>
#include <Windows.h>
#include <safeint.h>
using namespace std;

DWORD GetIl2CppAddress(const char* address) 
{
	HMODULE module = LoadLibraryA("GameAssembly.dll");
	DWORD dword_word = (DWORD)GetProcAddress(module, (LPCSTR)address);
	if (dword_word == NULL) {
		cout << "Library Is Don't Loaded Successfull!!!" << endl;
		exit(543);
	}
	return dword_word;
}
int main() 
{
	SetConsoleTitleA("Il2Cpp Finding Address");
	HMODULE game_asm = LoadLibraryA("GameAssembly.dll");
	printf("Loading Module...");
	Sleep(15000);
	if (game_asm == nullptr) {
		printf("\nModule not Founded!!!");
	}
	else 
	{
		cout << "\nModule is Founded, Address of this HMODULE: 0x" << (DWORD)game_asm << endl;
		Sleep(15000);
		cout << "\nFinding All Addresses of Il2Cpp DLLImport..." << endl;
		Sleep(35000);
		cout << "\nDomain Get Assemblies Address: 0x" << GetIl2CppAddress("il2cpp_domain_get_assemblies") << endl;
		Sleep(5000);
		cout << "\nDomain Get Image Assemblies Address: 0x" << GetIl2CppAddress("il2cpp_assembly_get_image");
		Sleep(5000);
		cout << "\nImage Get Name Assemblies Address: 0x" << GetIl2CppAddress("il2cpp_image_get_name");
		Sleep(5000);
		exit(12);
	}
}