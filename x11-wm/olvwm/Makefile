# Created by: smace
# $FreeBSD$

PORTNAME=	olvwm
PORTVERSION=	4.2
PORTREVISION=	1
CATEGORIES=	x11-wm
MASTER_SITES=	ftp://ftp.x.org/R5contrib/ \
		XCONTRIB/window_managers \
		http://komquats.com/distfiles/ \
		LOCAL/cy
DISTNAME=	${PORTNAME}4

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	olvwm4.Patch01.Z \
		olvwm4.Patch02.Z
PATCH_DIST_STRIP=	-p1

MAINTAINER=	cy@FreeBSD.org
COMMENT=	OpenLook Virtual Window manager

LIB_DEPENDS=	libxview.so:x11-toolkits/xview

REINPLACE_ARGS= -i ""
NO_WRKSUBDIR=	yes
USES=		imake tar:Z
USE_XORG=	xpm
XFREE86_HTML_MAN=	no

IMAKECPPFLAGS+=	-DXVDestDir=${STAGEDIR}${PREFIX}

pre-configure:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
	's|^#endif.*$$|#endif|;s|^#else.*$$|#else|;\
	s|^/\*\*/#*|XCOMM |'

.include <bsd.port.mk>
