#pragma once
#include <string>
#include <mutex>
#include <rpcndr.h>

namespace bzg
{
	class SharedLibrary
		/// The SharedLibrary class dynamically
		/// loads shared libraries at run-time.
	{
	public:
		SharedLibrary() = default;
		/// Creates a SharedLibrary object.

		virtual ~SharedLibrary() = default;
		/// Destroys the SharedLibrary. The actual library
		/// remains loaded.

		bool load(const std::string& path);
		/// Loads a shared library from the given path.
		/// Throws a LibraryAlreadyLoadedException if
		/// a library has already been loaded.
		/// Throws a LibraryLoadException if the library
		/// cannot be loaded.

		void unload();
		/// Unloads a shared library.

		bool isLoaded() const;
		/// Returns true iff a library has been loaded.

		bool hasSymbol(const std::string& name);
		/// Returns true iff the loaded library contains
		/// a symbol with the given name.

		void* getSymbol(const std::string& name);
		/// Returns the address of the symbol with
		/// the given name. For functions, this
		/// is the entry point of the function.
		/// Throws a NotFoundException if the symbol
		/// does not exist.

		const std::string& getPath() const;
		/// Returns the path of the library, as
		/// specified in a call to load() or the
		/// constructor.

	private:
		SharedLibrary(const SharedLibrary&) = delete;
		SharedLibrary& operator = (const SharedLibrary&) = delete;
		static std::mutex mutex_;
		void* handle_;
		std::string path_;
	};
}
