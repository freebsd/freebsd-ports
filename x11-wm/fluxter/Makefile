# Created by: Adam Weinberger
# $FreeBSD$

PORTNAME=	fluxter
PORTVERSION=	0.2.0
PORTREVISION=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.hydrus.org.uk/downloads/

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Desktop pager for the Fluxbox Slit

LICENSE=	GPLv2

USES=		gmake xorg

USE_XORG=	x11 ice xorgproto xt xaw xext sm
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/fluxter \
		${DATADIR}/README.fluxter \
		${DATADIR}/fluxter.bb \
		${DATADIR}/fluxter.nobb

post-patch:
	@${REINPLACE_CMD} -e "s|/fluxbox|/${PORTNAME}|g" \
		${WRKSRC}/Makefile.in ${WRKSRC}/data/README.fluxter \
		${WRKSRC}/data/Makefile.in

.include <bsd.port.mk>
