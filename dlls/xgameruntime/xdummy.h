#ifndef __XDUMMY_H
#define __XDUMMY_H

#include <stdint.h>
#include <winerror.h>
#include <windef.h>

typedef struct IXDummyImpl IXDummyImpl;

typedef struct IXDummyImplVtbl {
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(IXDummyImpl* This, REFIID riid, void** ppvObject);
    ULONG   (STDMETHODCALLTYPE *AddRef)(IXDummyImpl* This);
    ULONG   (STDMETHODCALLTYPE *Release)(IXDummyImpl* This);

    HRESULT (STDMETHODCALLTYPE *DoSomething)(IXDummyImpl* This);
} IXDummyImplVtbl;

struct IXDummyImpl {
    const IXDummyImplVtbl* lpVtbl;
};

#ifdef COBJMACROS
#ifndef WIDL_C_INLINE_WRAPPERS
/*** IUnknown methods ***/
#define IXDummyImpl_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IXDummyImpl_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IXDummyImpl_Release(This) (This)->lpVtbl->Release(This)
/*** IXDummy methods ***/
#define IXDummyImpl_DoSomething(This) (This)->lpVtbl->DoSomething(This)

#else
/*** IUnknown methods ***/
static inline HRESULT STDMETHODCALLTYPE IXDummyImpl_QueryInterface(IXDummyImpl* This,REFIID riid,void **ppvObject) {
    return This->lpVtbl->QueryInterface(This,riid,ppvObject);
}
static inline ULONG STDMETHODCALLTYPE IXDummyImpl_AddRef(IXDummyImpl* This) {
    return This->lpVtbl->AddRef(This);
}
static inline ULONG STDMETHODCALLTYPE IXDummyImpl_Release(IXDummyImpl* This) {
    return This->lpVtbl->Release(This);
}
/*** IXDummy methods ***/
static inline HRESULT STDMETHODCALLTYPE IXDummyImpl_DoSomething(IXDummyImpl* This) {
    return This->lpVtbl->DoSomething(This);
}
#endif
#endif

// 95fd18d2-74dd-4d7c-aa1b-0b51827665d6
DEFINE_GUID(CLSID_XDummyImpl, 0x95fd18d2, 0x74dd, 0x4d7c, 0xaa, 0x1b, 0x0b, 0x51, 0x82, 0x76, 0x65, 0xd6);

// 026b010c-06c3-4cdd-bbcb-43f229db1cff
DEFINE_GUID(IID_IXDummyImpl, 0x026b010c, 0x06c3, 0x4cdd, 0xbb, 0xcb, 0x43, 0xf2, 0x29, 0xdb, 0x1c, 0xff);

#endif