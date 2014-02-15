# Created by: Anonymous
# $FreeBSD$

PORTNAME=	clx
PORTVERSION=	0.7.4
PORTREVISION?=	1
CATEGORIES=	x11 lisp
MASTER_SITES=	http://common-lisp.net/~abridgewater/dist/clx/
PKGNAMEPREFIX=	cl-
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 client library for Common Lisp

LICENSE=	MIT

.if !defined(FASL_BUILD)
USE_ASDF=	yes
INFO=		clx
PLIST_SUB=	ASDF_PATHNAME="${ASDF_PATHNAME:S,^${PREFIX}/,,}" \
		ASDF_REGISTRY="${ASDF_REGISTRY:S,^${PREFIX}/,,}"

do-build:
	cd ${WRKSRC}/manual && makeinfo --no-split clx.texinfo

do-install:
	${MKDIR} ${STAGEDIR}${ASDF_PATHNAME} ${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/attributes.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/big-requests.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/buffer.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/bufmac.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/clx.asd ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/clx.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/depdefs.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/dependent.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/display.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/dpms.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/fonts.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/gcontext.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/gl.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/glx.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/graphics.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/image.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/input.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/keysyms.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/macros.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/manager.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/package.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/requests.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/resource.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/screensaver.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/shape.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/text.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/translate.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/xinerama.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/xrender.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/xtest.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${INSTALL_DATA} ${WRKSRC}/xvidmode.lisp ${STAGEDIR}${ASDF_PATHNAME}
	${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/debug.lisp ${STAGEDIR}${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/describe.lisp ${STAGEDIR}${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/event-test.lisp ${STAGEDIR}${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/keytrans.lisp ${STAGEDIR}${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/trace.lisp ${STAGEDIR}${ASDF_PATHNAME}/debug
	${INSTALL_DATA} ${WRKSRC}/debug/util.lisp ${STAGEDIR}${ASDF_PATHNAME}/debug
	${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/bezier.lisp ${STAGEDIR}${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/beziertest.lisp ${STAGEDIR}${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/clclock.lisp ${STAGEDIR}${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/clipboard.lisp ${STAGEDIR}${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/clx-demos.lisp ${STAGEDIR}${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/gl-test.lisp ${STAGEDIR}${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/hello.lisp ${STAGEDIR}${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/mandel.lisp ${STAGEDIR}${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/menu.lisp ${STAGEDIR}${ASDF_PATHNAME}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/zoid.lisp ${STAGEDIR}${ASDF_PATHNAME}/demo
	${MKDIR} ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/image.lisp ${STAGEDIR}${ASDF_PATHNAME}/test
	${INSTALL_DATA} ${WRKSRC}/test/trapezoid.lisp ${STAGEDIR}${ASDF_PATHNAME}/test
	${LN} -sf ${ASDF_PATHNAME}/clx.asd ${STAGEDIR}${ASDF_REGISTRY}
	${INSTALL_DATA} ${WRKSRC}/manual/*.info ${STAGEDIR}${PREFIX}/info
.endif # FASL_BUILD

.include "${.CURDIR}/../../devel/cl-asdf/bsd.cl-asdf.mk"
.include <bsd.port.mk>
