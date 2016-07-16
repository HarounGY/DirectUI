#pragma once

namespace DirectUI
{
	//�����麯���������أ��������˳��
	class UILIB_API AutoButton :public AccessibleButton
	{
	public:
		AutoButton(const AutoButton &);
		AutoButton();
		AutoButton & operator=(const AutoButton&);
		virtual ~AutoButton();

		static long __stdcall Create(Element* , unsigned long *, Element** );
		static IClassInfo* __stdcall GetClassInfoPtr();
		static long __stdcall Register();
		static void __stdcallSetClassInfoPtr(IClassInfo *);
		static class UID __stdcall Toggle();

		virtual IClassInfo* GetClassInfoW();
		virtual void OnEvent(Event *);

		long Initialize(Element *, unsigned long *);

	private:
		static IClassInfo* s_pClassInfo;
	};
}