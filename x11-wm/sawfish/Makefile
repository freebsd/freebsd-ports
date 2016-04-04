# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sawfish
PORTVERSION=	1.11.90
PORTEPOCH=	3
CATEGORIES=	x11-wm
MASTER_SITES=	http://download.tuxfamily.org/sawfish/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extensible window manager using Lisp-based scripting language

LICENSE=	ART20 GPLv2
LICENSE_COMB=	multi

BUILD_DEPENDS=	rep-gtk2>=0.90:x11-toolkits/rep-gtk2
LIB_DEPENDS=	librep.so:lang/librep
RUN_DEPENDS=	rep-gtk2>=0.90:x11-toolkits/rep-gtk2

USES=		gmake libtool makeinfo pathfix pkgconfig tar:xz
USE_XORG=	ice sm x11 xft xinerama xrandr xtst
USE_GNOME=	cairo gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		sawfish

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--without-nls

post-extract:
	@${RM} ${WRKSRC}/themes/StyleTab/Flat/.directory

post-patch:
	@${REINPLACE_CMD} -e \
		'/dnsdomainname/d' ${WRKSRC}/build-info
	@${REINPLACE_CMD} -e \
		'/KDEDIR/s|^|#|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|prog_name|program_name|g' ${WRKSRC}/src/main.c

post-build:
	${STRIP_CMD} ${WRKSRC}/src/.libs/*.so \
		${WRKSRC}/src/gtk-style

.include <bsd.port.mk>
