# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
# $FreeBSD$

PORTNAME=	enlightenment
PORTVERSION=	0.19.5
PORTEPOCH=	2
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/apps/${PORTNAME}/

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Artistic X window manager

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libefl.so:${PORTSDIR}/devel/efl \
		libelementary.so:${PORTSDIR}/x11-toolkits/elementary \
		libedbus.so:${PORTSDIR}/devel/e_dbus \
		libxcb-keysyms.so:${PORTSDIR}/x11/xcb-util-keysyms
RUN_DEPENDS=	${LOCALBASE}/lib/evas/utils/evas_image_loader.svg:${PORTSDIR}/graphics/evas_generic_loaders-svg

DIST_SUBDIR=	enlightenment
GNU_CONFIGURE=	yes
USES=		alias autoreconf desktop-file-utils execinfo libtool pathfix \
		iconv gmake pkgconfig tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
SUB_FILES=	pkg-message

CONFIGURE_ARGS=	--with-profile=MEDIUM_PC \
		--disable-connman --disable-bluez4 \
		--disable-device-udev --disable-mount-udisks

CPPFLAGS+=	-I${LOCALBASE}/include/e_dbus-1

.include "Makefile.plist"

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

post-patch:
	@${REINPLACE_CMD} -e \
		's/\(setuid_root_mode = a=rx,u+x\)s/\1/g' \
		${WRKSRC}/src/bin/Makefile.mk \
		${WRKSRC}/src/modules/Makefile_cpufreq.mk

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64: signal 10
.endif

.include <bsd.port.post.mk>
