PORTNAME=	gbsddialog
DISTVERSION=	0.9.1
CATEGORIES=	x11
MASTER_SITES=	${WWW}/releases/download/${PORTNAME}_${DISTVERSION:S/./-/g}/

MAINTAINER=	khorben@defora.org
COMMENT=	Drop in replacement for the "dialog" or "cdialog" programs
WWW=		https://github.com/khorben/gbsddialog

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		desktop-file-utils gettext-runtime gnome pkgconfig
USE_GNOME=	cairo gdkpixbuf2 glib20 gtk30 pango

CONFLICTS_INSTALL=	xdialog-*

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/Xdialog \
		${STAGEDIR}${PREFIX}/bin/gbsddialog

.include <bsd.port.mk>
