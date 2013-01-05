# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	stumpwm
PORTVERSION=	0.9.7
PORTREVISION=	9
CATEGORIES=	x11-wm lisp
MASTER_SITES=	SAVANNAH
DISTFILES=	${DISTNAME}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tiling, keyboard driven Window Manager written in Common Lisp

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-contrib-dir=${DATADIR}
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/stumpish \
		bin/${PORTNAME}
INFO=		${PORTNAME}
PORTEXAMPLES=	sample-stumpwmrc.lisp
PORTDATA=	*

OPTIONS_DEFINE=	SBCL EXAMPLES
OPTIONS_DEFAULT=	SBCL
SBCL_DESC=	Build with lang/sbcl (otherwise with lang/clisp)

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSBCL} || make(makesum) || defined(FETCH_ALL)
MASTER_SITES+=	http://common-lisp.net/~abridgewater/dist/clx/:clx
DISTFILES+=	clx-0.7.4.tgz:clx
.endif

.if ${PORT_OPTIONS:MSBCL}
CONFIGURE_ARGS+=	--with-lisp=sbcl
BUILD_DEPENDS+=	sbcl:${PORTSDIR}/lang/sbcl
.else
CONFIGURE_ARGS+=	--with-lisp=clisp
BUILD_DEPENDS+=	clisp:${PORTSDIR}/lang/clisp
.endif

.if empty(PORT_OPTIONS:MSBCL)
.if exists(${LOCALBASE}/bin/clisp) && \
    !exists(${LOCALBASE}/lib/clisp/full/clx.o)
IGNORE=		requires lang/clisp built with CLX_NEW option ON
.endif
.endif

.if ${PORT_OPTIONS:MSBCL}
post-extract:	.SILENT
	${LN} -sf ${WRKDIR}/clx*/*.asd ${WRKSRC}/cl-ppcre/*.asd ${WRKSRC}

post-patch:	.SILENT
	${REINPLACE_CMD} 's|sbcl_.*OPTS=|& \
		--disable-debugger \
		--no-userinit \
		--no-sysinit \
		--eval "(require :asdf)" \
		--eval "(pop asdf:*central-registry*)" \
		|' ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} 's/\(sb-introspect:function-\)arglist/\1lambda-list/' \
		${WRKSRC}/manual.lisp
.endif

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/stumpish ${PREFIX}/bin
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${TAR} cf - -C${WRKSRC}/contrib --exclude stumpish\* . \
		| ${TAR} xovf - -C${DATADIR}
.endif

.include <bsd.port.mk>
