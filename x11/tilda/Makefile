PORTNAME=	tilda
PORTVERSION=	1.5.0
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	3
CATEGORIES=	x11

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Drop down x11 terminal with transparency support
WWW=		https://github.com/lanoxx/tilda

LICENSE=	GPLv2

BUILD_DEPENDS=	vte3>=0:x11-toolkits/vte3
LIB_DEPENDS=	libconfuse.so:devel/libconfuse
RUN_DEPENDS=	vte3>=0:x11-toolkits/vte3

USES=		gmake gettext gnome pkgconfig autoreconf pathfix libtool xorg
USE_GITHUB=	yes
GH_ACCOUNT=	lanoxx
USE_GNOME+=	glib20 gtk30 gdkpixbuf2 pango
USE_XORG+=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-rpath

INSTALL_TARGET=	install-strip

DOCS=		AUTHORS ChangeLog HACKING.md README.md TODO.md

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} "		ATTENTION:"
	@${ECHO_MSG} "		If you are upgrade from version 0.09.1 or below,"
	@${ECHO_MSG} "		you'll need to delete your old config files and "
	@${ECHO_MSG} "		make them again."
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""

.include <bsd.port.mk>
