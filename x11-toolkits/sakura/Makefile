# Created by: chinsan
# $FreeBSD$

PORTNAME=	sakura
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits gnome
MASTER_SITES=	http://www.pleyades.net/david/projects/sakura/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Terminal emulator based on GTK and VTE

OPTIONS_DEFINE=	DOCS

USE_GNOME=	vte
USES=		cmake pkgconfig gettext
USE_BZIP2=	yes
LDFLAGS+=	-lintl

MAN1=		sakura.1

.include <bsd.port.options.mk>
post-patch:
	@${REINPLACE_CMD} -e '/NOT MATCHES "Debug"/d ; \
		 /"-O2"/d ; \
		's,share/man,man,g' ; \
		 /FILES INSTALL/d' ${WRKSRC}/CMakeLists.txt

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCSDIR}
.endif

.include <bsd.port.mk>
