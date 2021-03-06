#pragma once
// a direct wrapper to libclang c interface, thus the name.
//
// this wrapper's goal is to make the interface conform to
// the standard c++ coding style and naming scheme (aka STL
// naming scheme).
//
// only functions/types/enums that is used by the project
// if forwarded.
//
#include <clang-c/Index.h>
#include <utility>




#include "../forward/begin.hh"
namespace clang
{
	namespace c
	{
// this macro is used to create type alias
// i call it "type forwarding"
//
// usage:
// 		// create type alias:
// 		namespace index { FORWARD_TYPE(Index); }
//
// 		// equivalent to:
// 		namespace index { using type = CXIndex; }
//
// 		// using the aliased type
// 		index::type x;
//
#define FORWARD_TYPE(NAME) \
		STDWRAP_FORWARD_TYPE(CX ## NAME)

// this macro is used to create function alias in c++11.
// i call it "perfect function forwarding"
//
// usage:
// 		// create type alias:
// 		namespace index { FORWARD_FUNC(dispose, disposeIndex); }
//
// 		// equivalent to this code in c++14:
// 		namespace index
// 		{
//			template <class ...Args>
//			inline decltype(auto) dispose(Args&& ...args)
//			{
//				return clang_disposeIndex(std::forward<Args>(args)...);
//			}
// 		}
//
// 		// using the aliased function
// 		index::dispose(x);
//
#define FORWARD_FUNC(NAME, CNAME) \
		STDWRAP_FORWARD_FUNC(NAME, clang_ ## CNAME)




		namespace index
		{
			FORWARD_TYPE(Index);
			FORWARD_FUNC(create, createIndex);
			FORWARD_FUNC(dispose, disposeIndex);
		};

		namespace translation_unit
		{
			FORWARD_TYPE(TranslationUnit);
			FORWARD_FUNC(create_from_source_file, createTranslationUnitFromSourceFile);
			FORWARD_FUNC(dispose, disposeTranslationUnit);
			FORWARD_FUNC(get_cursor, getTranslationUnitCursor);
			FORWARD_FUNC(reparse, reparseTranslationUnit);
		};

		namespace cursor
		{
			FORWARD_TYPE(Cursor);
			FORWARD_FUNC(get_extent, getCursorExtent);
			FORWARD_FUNC(get_kind, getCursorKind);
			FORWARD_FUNC(get_spelling, getCursorSpelling);
			namespace childs
			{
				namespace visit_result
				{
					FORWARD_TYPE(ChildVisitResult);
					constexpr auto into = CXChildVisit_Recurse;
					constexpr auto next = CXChildVisit_Continue;
					constexpr auto stop = CXChildVisit_Break;
				};
				FORWARD_FUNC(visit, visitChildren);
			};
			namespace kind
			{
				FORWARD_TYPE(CursorKind);
				FORWARD_FUNC(get_spelling, getCursorKindSpelling);
				FORWARD_FUNC(is_declaration, isDeclaration);
				FORWARD_FUNC(is_reference, isReference);
			};
		};

		namespace range
		{
			FORWARD_TYPE(SourceRange);
			FORWARD_FUNC(get_start, getRangeStart);
			FORWARD_FUNC(get_end, getRangeEnd);
		};

		namespace location
		{
			FORWARD_TYPE(SourceLocation);
			FORWARD_FUNC(get_spelling, getSpellingLocation);
			FORWARD_FUNC(is_from_main_file, Location_isFromMainFile);
		};

		namespace string
		{
			FORWARD_TYPE(String);
			FORWARD_FUNC(dispose, disposeString);
			FORWARD_FUNC(cstr, getCString);
		};

		namespace unsaved_file
		{
			FORWARD_TYPE(UnsavedFile);
		};

		namespace options
		{
			FORWARD_FUNC(default_reparse, defaultReparseOptions);
		};

		namespace diagnostic
		{
			FORWARD_TYPE(Diagnostic);
			FORWARD_FUNC(dispose, disposeDiagnostic);
			FORWARD_FUNC(get, getDiagnostic);
			FORWARD_FUNC(get_count, getNumDiagnostics);
			FORWARD_FUNC(get_location, getDiagnosticLocation);
		};




#undef FORWARD_FUNC
#undef FORWARD_TYPE
	};
};
#include "../forward/end.hh"

