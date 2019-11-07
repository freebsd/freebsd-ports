# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sisctrl
PORTVERSION=	0.0.20051202
PORTREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	http://www.winischhofer.net/sis/

MAINTAINER=	bland@FreeBSD.org
COMMENT=	Display Control Panel for XFree86/X.org SiS driver

BROKEN=		unfetchable

USES=		gmake gnome pkgconfig xorg
USE_XORG=	x11 ice xxf86vm xinerama xv xrandr xext sm
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	 --with-xv-path=${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

PLIST_FILES=	bin/sisctrl man/man1/sisctrl.1x.gz

.include <bsd.port.mk>
