# New ports collection makefile for:	cl-clx
# Date created:				7 Oct 2010
# Whom:					Anonymous
#
# $FreeBSD$

PORTNAME=	clx
PORTVERSION=	0.7.4
CATEGORIES=	x11 lisp
MASTER_SITES=	http://common-lisp.net/~abridgewater/dist/clx/
PKGNAMEPREFIX=	cl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	swell.k@gmail.com
COMMENT=	X11 client library for Common Lisp

.if !defined(FASL_BUILD)
USE_ASDF=	yes
INFO=		clx
PLIST_SUB=	ASDF_PATHNAME="${ASDF_PATHNAME:S,^${PREFIX}/,,}" \
		ASDF_REGISTRY="${ASDF_REGISTRY:S,^${PREFIX}/,,}"

do-build:
	cd ${WRKSRC}/manual && makeinfo --no-split clx.texinfo

do-install:
	${MKDIR} ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/attributes.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/big-requests.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/buffer.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/bufmac.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/clx.asd ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/clx.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/depdefs.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/dependent.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/display.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/dpms.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/fonts.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/gcontext.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/gl.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/glx.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/graphics.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/image.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/input.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/keysyms.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/macros.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/manager.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/package.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/requests.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/resource.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/screensaver.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/shape.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/text.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/translate.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/xinerama.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/xrender.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/xtest.lisp ${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/xvidmode.lisp ${ASDF_PATHNAME}
	${MKDIR} ${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/debug.lisp ${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/describe.lisp ${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/event-test.lisp ${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/keytrans.lisp ${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/trace.lisp ${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/util.lisp ${ASDF_PATHNAME}/debug
	${MKDIR} ${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/bezier.lisp ${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/beziertest.lisp ${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/clclock.lisp ${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/clipboard.lisp ${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/clx-demos.lisp ${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/gl-test.lisp ${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/hello.lisp ${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/mandel.lisp ${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/menu.lisp ${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/zoid.lisp ${ASDF_PATHNAME}/demo
	${MKDIR} ${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/image.lisp ${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/trapezoid.lisp ${ASDF_PATHNAME}/test
	${LN} -sf ${ASDF_PATHNAME}/*.asd ${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/manual/*.info ${PREFIX}/info
.endif # FASL_BUILD

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
