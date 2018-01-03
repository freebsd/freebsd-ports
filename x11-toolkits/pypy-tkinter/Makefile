# Created by: David Naylor <dbn@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkinter
CATEGORIES=	x11-toolkits python

MAINTAINER=	python@FreeBSD.org
COMMENT=	PyPy bindings to the Tk widget set

USES=		tk

CFFI_MODULE=	_tkinter/tklib
CFFI_NAME=	tkffi

.include "${.CURDIR}/../../lang/pypy/bsd.pypy.cffi.mk"
.include <bsd.port.mk>
