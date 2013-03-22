# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sawfish
PORTVERSION=	1.8.2
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.tuxfamily.org/sawfish/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lisp configurable window manager

LICENSE=	GPLv2

BUILD_DEPENDS=	rep-gtk2>=0.90:${PORTSDIR}/x11-toolkits/rep-gtk2
LIB_DEPENDS=	cairo:${PORTSDIR}/graphics/cairo \
		rep:${PORTSDIR}/lang/librep
RUN_DEPENDS=	rep-gtk2>=0.90:${PORTSDIR}/x11-toolkits/rep-gtk2

USE_XZ=		yes
USE_XORG=	ice sm x11 xft xinerama xrandr
USES=		pathfix
USE_GNOME=	gnomehier gtk20
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MANCOMPRESSED=	yes
MAN1=		sawfish.1 sawfish-client.1 sawfish-config.1
INFO=		sawfish

post-patch:
	@${REINPLACE_CMD} -e \
		'/dnsdomainname/d' ${WRKSRC}/build-info
	@${REINPLACE_CMD} -e \
		'/KDEDIR/s|^|#|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/share/man/|/man/|g' ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e \
		's|prog_name|program_name|g' ${WRKSRC}/src/main.c

.include <bsd.port.mk>
