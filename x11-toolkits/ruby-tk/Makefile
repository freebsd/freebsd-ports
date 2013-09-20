# Created by: Yasuhiro Fukuma <yasuf@big.or.jp>
# $FreeBSD$

PORTNAME=	tk
PORTVERSION=	${RUBY_PORTVERSION}
PORTREVISION=	${RUBY_PORTREVISION}
PORTEPOCH=	1
CATEGORIES+=	x11-toolkits ruby tcl tk
MASTER_SITES=	# none
DISTFILES=	# none

MAINTAINER?=	ruby@FreeBSD.org
COMMENT?=	Ruby interface to the Tk widget set

DEPRECATED=	Does not work with Ruby 1.9
EXPIRATION_DATE=	2013-05-02

FETCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	. tkutil
USE_XORG=	x11

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_TK=		84+

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
BROKEN=	does not build with ruby 1.9
.endif

CONFIGURE_ARGS=	${RUBY_CONFIGURE_ARGS} \
		--with-X11-dir=${LOCALBASE} \
		--with-tcl-include=${TCL_INCLUDEDIR} \
		--with-tk-include=${TK_INCLUDEDIR}

MAKE_ARGS=	sitelibdir='$$(rubylibdir)'

.if defined(PKGNAMEPREFIX)
PKGNAMEPREFIX:=	${PKGNAMEPREFIX}${RUBY_PKGNAMEPREFIX}
.else
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
.endif

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -sf `cd ${PORTSDIR}/${RUBY_PORT}; ${MAKE} -V WRKDIR`/${PORTNAME} ${WRKDIR}/

pre-configure:
	@${REINPLACE_CMD} -e "s/8\.5 8\.4 8\.3 8\.2 8\.1 8\.0 .\../${TCL_VER}/g" \
		${WRKSRC}/extconf.rb

post-build:
	@(cd ${BUILD_WRKSRC}/tkutil; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET})

post-install:
	@(cd ${INSTALL_WRKSRC}/tkutil; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET})
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
	${CP} -R ${WRKSRC}/sample/* ${RUBY_MODEXAMPLESDIR}/
	${MKDIR} ${RUBY_MODDOCDIR}
. for d in MANUAL_tcltklib.eng MANUAL_tcltklib.eucj README.fork README.1st README.ActiveTcl README.tcltklib
	${INSTALL_DATA} ${WRKSRC}/${d} ${RUBY_MODDOCDIR}/
. endfor
.endif

.include <bsd.port.post.mk>
