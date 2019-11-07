# Created by: trevor
# $FreeBSD$

PORTNAME=	evilwm
PORTVERSION=	1.1.1
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.6809.org.uk/evilwm/

MAINTAINER=	lasg@lasg.dk
COMMENT=	Minimalist window manager based on 9wm

USES=		gmake localbase:ldflags xorg
USE_XORG=	x11 xpm xext xrandr xrender
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}" \
		mandir="${MANPREFIX}/man"

PLIST_FILES=	bin/evilwm \
		man/man1/evilwm.1.gz \
		share/applications/evilwm.desktop
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ChangeLog README TODO doc/standards.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
