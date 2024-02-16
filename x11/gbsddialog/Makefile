PORTNAME=	gbsddialog
DISTVERSION=	0.8.0
CATEGORIES=	x11
MASTER_SITES=	${WWW}/releases/download/${PORTNAME}_${DISTVERSION:S/./-/g}/

MAINTAINER=	khorben@defora.org
COMMENT=	Drop in replacement for the "dialog" or "cdialog" programs
WWW=		https://github.com/khorben/gbsddialog

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libharfbuzz.so:print/harfbuzz

USES=		gnome pkgconfig gettext-runtime
USE_GNOME=	gtk30 pango cairo gdkpixbuf2 glib20

MAKE_ARGS+=	MANDIR=${PREFIX}/man

OPTIONS_DEFINE=	DOCS

CONFLICTS_INSTALL=	xdialog-*

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/Xdialog \
		${STAGEDIR}${PREFIX}/bin/gbsddialog

.include <bsd.port.mk>
