# New ports collection makefile for:  tktable
# Date created:         25 Jun 2003
# Whom:                 thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	tktable
PORTVERSION=	2.8
PORTREVISION=	1
CATEGORIES=	x11-toolkits tk84
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:S/tk/Tk/}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A table/matrix widget extension to tk/tcl

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-tcl=${LOCALBASE}/lib/tcl${TK_VER} \
		--with-tk=${LOCALBASE}/lib/tk${TK_VER} \
		--with-tclinclude=${LOCALBASE}/include/tcl${TK_VER} \
		--with-tkinclude=${LOCALBASE}/include/tk${TK_VER} \
		--with-x=${X11BASE}
USE_REINPLACE=	yes

TK_VER=		8.4
PLIST_SUB=	DESTDIR=lib/${DISTNAME}

post-patch:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s:install-libraries install-doc:install-libraries:" \
		${WRKSRC}/Makefile.in
.else
	@${REINPLACE_CMD} -e "s:%%DOCSDIR%%:${DOCSDIR}:g" ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.if defined(MAINTAINER_MODE)
test: build
	(cd ${WRKSRC};  \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} test)
.endif

.include <bsd.port.mk>
