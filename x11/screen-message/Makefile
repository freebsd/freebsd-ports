PORTNAME=	screen-message
DISTVERSION=	0.29
CATEGORIES=	x11

MAINTAINER=	gspurki@gmail.com
COMMENT=	Very simple tool to display some text as large as possible
WWW=		https://sm.nomeata.de/

LICENSE=	GPLv2+

USES=		autoreconf desktop-file-utils gettext-runtime gmake gnome \
		pkgconfig

USE_GITHUB=	yes
GH_ACCOUNT=	nomeata
GH_TAGNAME=	d4f2d831672eaf8283406d8f1fda4449e9c06d9f
USE_GNOME=	atk cairo gdkpixbuf glib20 gtk30

GNU_CONFIGURE=	yes

MAKE_ARGS=	execgamesdir=${PREFIX}/bin

PLIST_FILES=	bin/sm \
		share/applications/sm.desktop \
		share/icons/hicolor/48x48/apps/sm.png \
		share/man/man1/sm.1.gz

.include <bsd.port.mk>
