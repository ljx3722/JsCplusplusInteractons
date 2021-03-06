// MainDlg.h : interface of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////
#pragma once

class CMainDlg : public SHostWnd
{
public:
	CMainDlg();
	~CMainDlg();

	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	
	void OnBtnMsgBox();
	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);

	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);

protected:// 工具栏事件
	HRESULT OnBtnWebkitGo();
	HRESULT OnBtnWebkitRefresh();
	HRESULT OnBtnWebkitBackward();
	HRESULT OnBtnWebkitForward();

protected:// 调用 js、js 调用 C++
	HRESULT OnBtnRunJs();
	HRESULT OnBtnRunCPlusPlus();

protected:
	//soui消息
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
		EVENT_NAME_COMMAND(L"btn_webkit_go", OnBtnWebkitGo)
		EVENT_NAME_COMMAND(L"btn_webkit_refresh", OnBtnWebkitRefresh)
		EVENT_NAME_COMMAND(L"btn_webkit_back", OnBtnWebkitBackward)
		EVENT_NAME_COMMAND(L"btn_webkit_forward", OnBtnWebkitForward)
		EVENT_NAME_COMMAND(L"button_run_js", OnBtnRunJs)
		EVENT_NAME_COMMAND(L"button_run_c_plus_plus", OnBtnRunCPlusPlus)
		EVENT_MAP_END()
	//HostWnd真实窗口消息处理
	BEGIN_MSG_MAP_EX(CMainDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		MSG_WM_KEYDOWN(OnKeyDown)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
};
