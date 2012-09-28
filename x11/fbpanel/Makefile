# Created by: Tobias Roth <ports@fsck.ch>
# $FreeBSD$

PORTNAME=	fbpanel
PORTVERSION=	6.1
PORTREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	SF
EXTRACT_SUFX=	.tbz2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight, NETWM compliant X11 desktop panel

LICENSE=	GPLv2

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_PKGCONFIG=	build

MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e 's|bash|sh|' ${WRKSRC}/scripts/install.sh
	@${REINPLACE_CMD} -e 's|@DATADIR@|${DATADIR}|' \
		${WRKSRC}/data/man/${MAN1}.in

post-install:
	${INSTALL_MAN} ${WRKSRC}/data/man/${MAN1} ${MANPREFIX}/man/man1

.include <bsd.port.mk>
