PORTNAME=	waylock
DISTVERSIONPREFIX=	v
DISTVERSION=	1.5.0
CATEGORIES=	x11 wayland

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small screenlocker for Wayland compositors
WWW=		https://codeberg.org/ifreund/waylock

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	wayland-protocols>0:graphics/wayland-protocols
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libxkbcommon.so:x11/libxkbcommon
RUN_DEPENDS=	unix-selfauth-helper>0:security/unix-selfauth-helper

# There is an LLVM/zig016 regression which causes waylock to fail to run when
# using any of the release modes with this error:
# ld-elf.so.1: /lib/libc.so.7: Undefined symbol "environ"
USES=		pkgconfig zig:015
USE_GITHUB=	yes
GH_ACCOUNT=	ifreund

PLIST_FILES=	bin/${PORTNAME} \
		etc/pam.d/${PORTNAME}

OPTIONS_DEFINE=		MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_ZIG_BOOL=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
