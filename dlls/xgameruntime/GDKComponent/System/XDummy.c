#include "XDummy.h"

WINE_DEFAULT_DEBUG_CHANNEL(gdkc);

static inline struct x_dummy *impl_from_IXDummyImpl( IXDummyImpl *iface )
{
    return CONTAINING_RECORD( iface, struct x_dummy, IXDummyImpl_iface );
}

static HRESULT WINAPI x_dummy_QueryInterface( IXDummyImpl *iface, REFIID iid, void **out )
{
    struct x_dummy *impl = impl_from_IXDummyImpl( iface );

    TRACE( "iface %p, iid %s, out %p.\n", iface, debugstr_guid( iid ), out );

    if (IsEqualGUID( iid, &IID_IUnknown ) ||
        IsEqualGUID( iid, &IID_IXDummyImpl ))
    {
        *out = &impl->IXDummyImpl_iface;
        impl->IXDummyImpl_iface.lpVtbl->AddRef( *out );
        return S_OK;
    }

    FIXME( "%s not implemented, returning E_NOINTERFACE.\n", debugstr_guid( iid ) );
    *out = NULL;
    return E_NOINTERFACE;
}

static ULONG WINAPI x_dummy_AddRef( IXDummyImpl *iface )
{
    struct x_dummy *impl = impl_from_IXDummyImpl( iface );
    ULONG ref = InterlockedIncrement( &impl-> ref );
    TRACE( "iface %p increasing refcount to %lu.\n", iface, ref );
    return ref;
}

static ULONG WINAPI x_dummy_Release( IXDummyImpl *iface )
{
    struct x_dummy *impl = impl_from_IXDummyImpl( iface );
    ULONG ref = InterlockedDecrement( &impl->ref );
    TRACE( "iface %p decreasing refcount to %lu.\n", iface, ref );
    return ref;
}

static HRESULT WINAPI x_dummy_DoSomething( IXDummyImpl *iface )
{
    TRACE("XDummyImpl DoSomething called\n");
    return S_OK;
}

static const struct IXDummyImplVtbl x_dummy_vtbl =
{
    x_dummy_QueryInterface,
    x_dummy_AddRef,
    x_dummy_Release,
    /* IXDummyImpl methods */
    x_dummy_DoSomething
};

static struct x_dummy x_dummy =
{
    {&x_dummy_vtbl},
    0,
};

IXDummyImpl *x_dummy_impl = &x_dummy.IXDummyImpl_iface;