# Created by: Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>

PORTNAME=	enlightenment
PORTVERSION=	0.24.2
PORTEPOCH=	2
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/apps/${PORTNAME}/
DIST_SUBDIR=	enlightenment

MAINTAINER=	enlightenment@FreeBSD.org
COMMENT=	Artistic and fast X window manager

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libefl.so:devel/efl \
		libpulse.so:audio/pulseaudio

USES=		compiler:c11 cpe desktop-file-utils gettext-tools gnome \
		localbase:ldflags meson ninja iconv libtool pathfix pkgconfig \
		tar:xz xorg
USE_XORG=	xcb
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

MESON_ARGS=	-Dsystemd=false -Ddevice-udev=false \
		-Dmount-udisks=false -Dmount-eeze=false -Dbluez5=false \
		-Dconnman=false --sysconfdir=/usr/local/etc

INSTALLS_ICONS=	yes

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext-runtime
NLS_MESON_TRUE=		nls

# MESON normalizes ${ARCH} so we cannot use it 'AS IS' without conversion
CURRENT_ARCH=	${ARCH}
.if ${CURRENT_ARCH} == amd64
ENLIGHTENMENT_ARCH=     ${OPSYS:tl}-x86_64
.elif ${CURRENT_ARCH} == i386
ENLIGHTENMENT_ARCH=     ${OPSYS:tl}-x86
.elif ${CURRENT_ARCH:Mpowerpc64*}
ENLIGHTENMENT_ARCH=     ${OPSYS:tl}-ppc64
.elif ${CURRENT_ARCH} == powerpc
ENLIGHTENMENT_ARCH=     ${OPSYS:tl}-ppc
.elif ${CURRENT_ARCH:Marmv?}
ENLIGHTENMENT_ARCH=	${OPSYS:tl}-arm
.else
ENLIGHTENMENT_ARCH=     ${OPSYS:tl}-${CURRENT_ARCH}
.endif

ENLIGHTENMENT_VERSION=	0.24.2
PLIST_SUB=              ENLIGHTENMENT_ARCH=${ENLIGHTENMENT_ARCH}-${ENLIGHTENMENT_VERSION}

.include <bsd.port.mk>
