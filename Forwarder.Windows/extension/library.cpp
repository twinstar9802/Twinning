//

#include <wrl/module.h>
#include "./forward_explorer_command.hpp"

// ----------------

STDAPI_(BOOL) DllMain (
	HINSTANCE hinstDLL,
	DWORD     fdwReason,
	LPVOID    lpvReserved
) {
	if (fdwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hinstDLL);
	}
	return TRUE;
}

STDAPI DllGetActivationFactory (
	HSTRING                activatableClassId,
	IActivationFactory * * factory
) {
	return Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule().GetActivationFactory(activatableClassId, factory);
}

STDAPI DllGetClassObject (
	REFCLSID     rclsid,
	REFIID       riid,
	LPVOID FAR * ppv
) {
	return Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule().GetClassObject(rclsid, riid, ppv);
}

STDAPI DllCanUnloadNow (
) {
	return Microsoft::WRL::Module<Microsoft::WRL::InProc>::GetModule().Terminate() ? S_OK : S_FALSE;
}

// ----------------

using Twinning::Forwarder::ForwardExplorerCommand;
CoCreatableClass(ForwardExplorerCommand);
CoCreatableClassWrlCreatorMapInclude(ForwardExplorerCommand);