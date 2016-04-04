# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	devilspie
PORTVERSION=	0.23
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.burtonini.com/computing/

MAINTAINER=	w.schwarzenfeld@utanet.at
COMMENT=	Window manipulation tool

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwnck-3.so:x11-toolkits/libwnck3

USES=		gettext gmake pkgconfig tar:xz
USE_GNOME=	libwnck intltool
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lX11

PORTDOCS=	AUTHORS NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
