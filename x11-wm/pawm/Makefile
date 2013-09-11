# Created by: trevor
# $FreeBSD$

PORTNAME=	pawm
PORTVERSION=	2.3.0
CATEGORIES=	x11-wm
MASTER_SITES=	http://www.pleyades.net/pawm/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Puto Amo Window Manager

USE_BZIP2=	yes
USE_XORG=	x11 xft xrandr xrender xpm
USES=		cmake pkgconfig
CMAKE_ARGS=	-DCMAKE_CONFIG_PREFIX:STRING="${PREFIX}/etc" \
		-DX11_LIBRARY_DIRS:STRING="${LOCALBASE}/lib"

.if defined(WITH_SN)
LIB_DEPENDS+=	startup-notification-1.0:${PORTSDIR}/x11/startup-notification
CFLAGS+=	-DENABLE_STARTUP -DSN_API_NOT_YET_FROZEN \
		`pkg-config --cflags --libs libstartup-notification-1.0`
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/"\/etc"/s|^|#| ; \
		 /"-O2"/s|^|#| ; \
		 /LINK_DIRECTORIES/s|\.|| ; \
		 /INSTALL/s| /etc| etc|' ${WRKSRC}/CMakeLists.txt

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for ii in AUTHORS Changelog.old GPL INSTALL README TODO
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
