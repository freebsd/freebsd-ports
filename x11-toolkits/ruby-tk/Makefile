# New ports collection makefile for:	ruby-tk
# Date created:		15 March 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	tk
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION=	${RUBY_PORTREVISION}
PORTEPOCH=	1
CATEGORIES+=	x11-toolkits ruby tk${TK_VERSION:C/[^0-9]//g} tcl${TK_VERSION:C/[^0-9]//g}
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER?=	stas@FreeBSD.org
COMMENT?=	Ruby interface to the Tk widget set

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	. tkutil
USE_XLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

TK_VERSION?=	8.4
.if defined(WITH_TCLTK_JP)
TCLPORTDIR?=	${PORTSDIR}/japanese/tcl
TKPORTDIR?=	${PORTSDIR}/japanese/tk
.else
TCLPORTDIR?=	${PORTSDIR}/lang/tcl
TKPORTDIR?=	${PORTSDIR}/x11-toolkits/tk
.endif

LIB_DEPENDS=	tcl${TK_VERSION:S/.//}:${TCLPORTDIR}${TK_VERSION:C/[^0-9]//g} \
		tk${TK_VERSION:S/.//}:${TKPORTDIR}${TK_VERSION:C/[^0-9]//g}

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	${RUBY_CONFIGURE_ARGS} \
		--with-X11-dir=${X11BASE} \
		--with-tcl-include=${LOCALBASE}/include/tcl${TK_VERSION} \
		--with-tk-include=${LOCALBASE}/include/tk${TK_VERSION}
.if defined(WITH_TCLTK_JP)
CONFIGURE_ARGS+=--with-tcllib=tcl${TK_VERSION:S/.//} --with-tklib=tk${TK_VERSION:S/.//}
.endif

.if ${RUBY_VER} >= 1.7
MAKE_ARGS=	sitelibdir='$$(rubylibdir)'
.endif

.if defined(PKGNAMEPREFIX)
PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}
.else
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${PORTSDIR}/${RUBY_PORT}; ${MAKE} -V WRKDIR`/${PORTNAME} ${WRKDIR}/

post-build:
	@(cd ${BUILD_WRKSRC}/tkutil; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	@(cd ${INSTALL_WRKSRC}/tkutil; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
.if ${RUBY_VER} >= 1.8
	${MKDIR} ${RUBY_MODDOCDIR}
.for d in MANUAL_tcltklib.eng MANUAL_tcltklib.eucj README.fork README.1st README.ActiveTcl README.tcltklib
	${INSTALL_DATA} ${WRKSRC}/${d} ${RUBY_MODDOCDIR}/
.endfor
.endif
.endif

.include <bsd.port.post.mk>
