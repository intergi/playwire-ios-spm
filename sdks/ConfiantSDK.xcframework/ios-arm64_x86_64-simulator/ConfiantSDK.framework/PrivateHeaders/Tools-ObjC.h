#ifndef Tools_ObjC_h
#define Tools_ObjC_h

#import <Foundation/Foundation.h>

NS_INLINE id const _Nullable tryCatchObjC(NSException const * __autoreleasing _Nullable * const _Nonnull outExceptionPtr, id const _Nullable(^_Nonnull NS_NOESCAPE tryBlock)(void)) {
	id _Nullable result = NULL;
	NSException const * _Nullable exceptionOut = NULL;
	@try {
		result = tryBlock();
	} @catch (NSException const * const _Nonnull exception) {
		exceptionOut = exception;
	}
	(*outExceptionPtr) = exceptionOut;
	return result;
}

#endif
