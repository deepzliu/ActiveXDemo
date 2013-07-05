

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri May 24 16:38:01 2013
 */
/* Compiler settings for ScreenCaptureX.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __ScreenCaptureXidl_h__
#define __ScreenCaptureXidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DScreenCaptureX_FWD_DEFINED__
#define ___DScreenCaptureX_FWD_DEFINED__
typedef interface _DScreenCaptureX _DScreenCaptureX;
#endif 	/* ___DScreenCaptureX_FWD_DEFINED__ */


#ifndef ___DScreenCaptureXEvents_FWD_DEFINED__
#define ___DScreenCaptureXEvents_FWD_DEFINED__
typedef interface _DScreenCaptureXEvents _DScreenCaptureXEvents;
#endif 	/* ___DScreenCaptureXEvents_FWD_DEFINED__ */


#ifndef __ScreenCaptureX_FWD_DEFINED__
#define __ScreenCaptureX_FWD_DEFINED__

#ifdef __cplusplus
typedef class ScreenCaptureX ScreenCaptureX;
#else
typedef struct ScreenCaptureX ScreenCaptureX;
#endif /* __cplusplus */

#endif 	/* __ScreenCaptureX_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __ScreenCaptureXLib_LIBRARY_DEFINED__
#define __ScreenCaptureXLib_LIBRARY_DEFINED__

/* library ScreenCaptureXLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_ScreenCaptureXLib;

#ifndef ___DScreenCaptureX_DISPINTERFACE_DEFINED__
#define ___DScreenCaptureX_DISPINTERFACE_DEFINED__

/* dispinterface _DScreenCaptureX */
/* [uuid] */ 


EXTERN_C const IID DIID__DScreenCaptureX;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("23FA8459-94D0-43C1-8122-09BDBF252183")
    _DScreenCaptureX : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DScreenCaptureXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DScreenCaptureX * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DScreenCaptureX * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DScreenCaptureX * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DScreenCaptureX * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DScreenCaptureX * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DScreenCaptureX * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DScreenCaptureX * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DScreenCaptureXVtbl;

    interface _DScreenCaptureX
    {
        CONST_VTBL struct _DScreenCaptureXVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DScreenCaptureX_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DScreenCaptureX_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DScreenCaptureX_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DScreenCaptureX_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DScreenCaptureX_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DScreenCaptureX_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DScreenCaptureX_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DScreenCaptureX_DISPINTERFACE_DEFINED__ */


#ifndef ___DScreenCaptureXEvents_DISPINTERFACE_DEFINED__
#define ___DScreenCaptureXEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DScreenCaptureXEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DScreenCaptureXEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F0D0F0D8-D8A2-45D4-96B1-A3AE62D9B7CC")
    _DScreenCaptureXEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DScreenCaptureXEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DScreenCaptureXEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DScreenCaptureXEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DScreenCaptureXEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DScreenCaptureXEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DScreenCaptureXEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DScreenCaptureXEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DScreenCaptureXEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DScreenCaptureXEventsVtbl;

    interface _DScreenCaptureXEvents
    {
        CONST_VTBL struct _DScreenCaptureXEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DScreenCaptureXEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DScreenCaptureXEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DScreenCaptureXEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DScreenCaptureXEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DScreenCaptureXEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DScreenCaptureXEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DScreenCaptureXEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DScreenCaptureXEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ScreenCaptureX;

#ifdef __cplusplus

class DECLSPEC_UUID("4E491DBB-A221-4B86-A740-74CDC5AF53A5")
ScreenCaptureX;
#endif
#endif /* __ScreenCaptureXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


