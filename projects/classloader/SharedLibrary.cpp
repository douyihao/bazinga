#include "SharedLibrary.h"
#include <Windows.h>
#include <locale>
#include <codecvt>
bool bzg::SharedLibrary::load(const std::string& path)
{std::lock_guard<std::mutex> lck(mutex_);

	if (handle_)
		return false;
	std::wstring upath;
	typedef  std::codecvt<wchar_t, char, std::mbstate_t> mbp;
	std::wstring_convert<mbp> converter(new mbp("CHS"));
	upath = converter.from_bytes(path);
	handle_ = LoadLibraryW(upath.c_str());
	if (!handle_)
		return false;
	path_ = path;
}
