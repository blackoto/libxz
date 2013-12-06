#pragma once
#include "base/basictypes.h"
#include "base/memory/scoped_ptr.h"
#include <string>
template <typename T> struct DefaultSingletonTraits;

namespace base {
	class MessageLoopForUI;
}

class RootNode;
class WindowNode;
class Application
{
public:
	static Application* GetInstance();

	void Init(base::MessageLoopForUI* loop);
	void Run();

	static WindowNode* CreateWindowNode();
	void LoadFromFile(const std::wstring& file);
private:
	Application(void);
	static LRESULT CALLBACK WndProc(HWND window,
		UINT message,
		WPARAM w_param,
		LPARAM l_param);

	LRESULT HandleMessage(HWND hwnd, UINT message, WPARAM w_param, LPARAM l_param);


private:
	HWND root_wnd_;

	base::MessageLoopForUI* main_message_loop_;

	scoped_ptr<RootNode> root_node_;

	friend struct DefaultSingletonTraits<Application>;
	DISALLOW_COPY_AND_ASSIGN(Application);
};
