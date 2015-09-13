#pragma once

#ifdef DRAW_DLL_EXPORT
#define EMB_DRAW_API __declspec(dllexport)
#else
#define EMB_DRAW_API __declspec(dllimport)
#endif