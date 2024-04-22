PORTNAME=	gtklock
DISTVERSIONPREFIX=	v
DISTVERSION=	3.0.0
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK-based lockscreen for Wayland
WWW=		https://github.com/jovanlanik/gtklock

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgtk-session-lock.so:x11-toolkits/gtk-session-lock
RUN_DEPENDS=	unix-selfauth-helper>0:security/unix-selfauth-helper

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtk30
GH_ACCOUNT=	jovanlanik
LDFLAGS_i386=	-Wl,-z,notext
PLIST_FILES=	bin/${PORTNAME} \
		etc/pam.d/${PORTNAME}

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages
MANPAGES_PLIST_FILES=	share/man/man1/${PORTNAME}.1.gz

.include <bsd.port.mk>
