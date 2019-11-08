# $FreeBSD$

PORTNAME=	screen-message
PORTVERSION=	0.25
CATEGORIES=	x11

MAINTAINER=	mail@dhauck.eu
COMMENT=	Very simple tool to display some text as large as possible

LICENSE=	GPLv2+

USES=		autoreconf gettext-runtime gmake gnome pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	nomeata
GH_TAGNAME=	82c01f85d9ca9d0a3b2fe811249808d2fe4703ba

GNU_CONFIGURE=	yes
USE_GNOME=	gtk30 atk glib20 cairo gdkpixbuf2
INSTALLS_ICONS=	yes

PLIST_FILES=	bin/sm \
		man/man6/sm.6.gz \
		share/applications/sm.desktop \
		share/icons/hicolor/48x48/apps/sm.png

MAKE_ARGS=	execgamesdir=${PREFIX}/bin

.include <bsd.port.mk>
