# New ports collection makefile for:	openbox
# Date created:				2002-04-28
# Whom:					trevor
# based on the blackbox port
#
# $FreeBSD$
#

PORTNAME=	openbox
PORTVERSION=	2.2.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://icculus.org/openbox/releases/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Derived from, and similar to, Blackbox

LIB_DEPENDS=	Xft.2:${PORTSDIR}/x11-fonts/Xft
RUN_DEPENDS=	xsetbg:${PORTSDIR}/x11/xloadimage

MAN1=		openbox.1 osetroot.1 osetbg.1

USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes

.if defined(WITH_XINERAMA)
CONFIGURE_ARGS=	--enable-xinerama
.endif

pre-everything:
.if !defined(WITH_XINERAMA)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_XINERAMA=yes for enable support of the Xinerama extension"
	@${ECHO_MSG} ""
.endif

post-extract:
	@${MV} ${WRKSRC}/doc/bsetbg.1 ${WRKSRC}/doc/osetbg.1
	@${MV} ${WRKSRC}/doc/bsetroot.1 ${WRKSRC}/doc/osetroot.1
	@${MV} ${WRKSRC}/util/bsetbg ${WRKSRC}/util/osetbg

post-patch:
	@${REINPLACE_CMD} -e 's|bsetbg|osetbg|g ; s|bsetroot|osetroot|g ; \
		s|Bsetroot|Osetroot|g' ${WRKSRC}/data/README.style \
		${WRKSRC}/data/styles/*	${WRKSRC}/doc/*

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
