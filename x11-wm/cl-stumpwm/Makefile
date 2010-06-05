# New ports collection makefile for:	stumpwm
# Date created:				2008-02-20
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	stumpwm
PORTVERSION=	0.9.7
CATEGORIES=	x11-wm
MASTER_SITES=	SAVANNAH
DISTFILES=	${DISTNAME}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiling, keyboard driven Window Manager written in Common Lisp

GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/${PORTNAME}
INFO=		${PORTNAME}

OPTIONS=	SBCL "Build with lang/sbcl (otherwise with lang/clisp)" off

.include <bsd.port.options.mk>

.if defined(WITH_SBCL) || make(makesum) || defined(FETCH_ALL)
MASTER_SITES+=	http://common-lisp.net/~abridgewater/dist/clx/:clx
DISTFILES+=	clx-0.7.4.tgz:clx
.endif

.if defined(WITH_SBCL)
CONFIGURE_ARGS=	--with-lisp=sbcl
BUILD_DEPENDS+=	sbcl:${PORTSDIR}/lang/sbcl
.else
CONFIGURE_ARGS=	--with-lisp=clisp
BUILD_DEPENDS+=	clisp:${PORTSDIR}/lang/clisp
.endif

.if !defined(WITH_SBCL)
.if exists(${LOCALBASE}/bin/clisp) && \
    !exists(${LOCALBASE}/lib/clisp/full/clx.o)
IGNORE=		requires lang/clisp built with CLX_NEW option ON
.endif
.endif

.if defined(WITH_SBCL)
post-extract:	.SILENT
	${LN} -sf ${WRKDIR}/clx*/*.asd ${WRKSRC}/cl-ppcre/*.asd ${WRKSRC}

post-patch:	.SILENT
	${REINPLACE_CMD} 's|sbcl_.*OPTS=|&--disable-debugger --no-userinit \
		--eval "(require :asdf)" \
		--eval "(pop asdf:*central-registry*)" |' \
		${WRKSRC}/Makefile.in
	${REINPLACE_CMD} 's/\(sb-introspect:function-\)arglist/\1lambda-list/' \
		${WRKSRC}/manual.lisp
.endif

.include <bsd.port.mk>
