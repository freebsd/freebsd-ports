# Created by: chinsan
# $FreeBSD$

PORTNAME=	sakura
PORTVERSION=	3.3.4
PORTREVISION=	1
CATEGORIES=	x11 gnome
MASTER_SITES=	http://launchpadlibrarian.net/235602098/

MAINTAINER=	danilo@FreeBSD.org
COMMENT=	Terminal emulator based on GTK and VTE

LICENSE=	GPLv2

OPTIONS_DEFINE=	DOCS

USE_GNOME=	vte3
USES=		cmake pkgconfig gettext tar:bzip2
LDFLAGS+=	-lintl

post-patch:
	@${REINPLACE_CMD} -e '/NOT MATCHES "Debug"/d ; \
		 /"-O2"/d ; \
		's,share/man,man,g' ; \
		 /FILES INSTALL/d' ${WRKSRC}/CMakeLists.txt

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
