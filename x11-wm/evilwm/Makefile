PORTNAME=	evilwm
DISTVERSION=	1.4.3
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.6809.org.uk/evilwm/

MAINTAINER=	cmanv@duck.com
COMMENT=	Minimalist window manager based on 9wm
WWW=		https://www.6809.org.uk/evilwm/

LICENSE=	AEWM
LICENSE_FILE=	${WRKSRC}/README
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_NAME=	AEWM License

USES=		gmake localbase:ldflags xorg
USE_XORG=	x11 xpm xext xrandr xrender
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}" \
		mandir="${PREFIX}/share/man"
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/evilwm \
		share/man/man1/evilwm.1.gz \
		share/applications/evilwm.desktop
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ChangeLog README TODO doc/build.html doc/evilwm.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
