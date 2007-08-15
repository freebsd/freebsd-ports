# New ports collection makefile for:	matchbox
# Date created:				2002-07-14
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	matchbox
PORTVERSION=	1.2
DISTVERSIONPREFIX=	window-manager-
CATEGORIES=	x11-wm
MASTER_SITES=	http://matchbox-project.org/sources/matchbox-window-manager/${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Window manager suitable for low-resolution screens

USE_BZIP2=	yes
USE_GNOME=	gnometarget
USE_XORG=	xfixes xcursor xext
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/matchbox-window-manager bin/matchbox-remote \
		etc/matchbox/kbdconfig
PLIST_DIRS=	etc/matchbox
PORTDOCS=	AUTHORS ChangeLog NEWS README

.include <bsd.port.pre.mk>

.if defined(WITHOUT_XFT)
CONFIGURE_ARGS+=	--enable-standalone
.else
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
CONFIGURE_ARGS+=	--enable-standalone-xft
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/GCC_/s|-g -Wall -fno-strict-aliasing||g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/matchbox-remote ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/matchbox-window-manager ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/etc/matchbox
	${INSTALL_DATA} ${WRKSRC}/data/kbdconfig ${PREFIX}/etc/matchbox
.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.post.mk>
