# New ports collection makefile for:	fbpanel
# Date created:		Sat Jun 26 13:43:50 CEST 2004
# Whom:			Tobias Roth <ports@fsck.ch>
#
# $FreeBSD$
#

PORTNAME=	fbpanel
PORTVERSION=	6.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF
EXTRACT_SUFX=	.tbz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Desktop panel that includes a taskbar, pager, launchbar and more

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_XORG=	x11 xmu xpm
USE_GNOME=	gtk20
HAS_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PKGCONFIG=	build

CONFIGURE_ARGS+=	--prefix=${PREFIX}

MAN1=		fbpanel.1
MANCOMPRESSED=	no

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' ${WRKSRC}/scripts/rfs-pkg-config
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' ${WRKSRC}/scripts/install.sh
	@${REINPLACE_CMD} -e 's|@DATADIR@|${DATADIR}|g' ${WRKSRC}/data/man/${PORTNAME}.1.in

post-install:
	@${INSTALL_MAN} ${WRKSRC}/data/man/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>
