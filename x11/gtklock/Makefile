PORTNAME=	gtklock
DISTVERSIONPREFIX=	v
DISTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	x11 wayland

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	GTK-based lockscreen for Wayland
WWW=		https://github.com/jovanlanik/gtklock

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc
LIB_DEPENDS=	libwayland-client.so:graphics/wayland \
		libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell
RUN_DEPENDS=	unix-selfauth-helper>0:security/unix-selfauth-helper

USES=		compiler:c11 gmake gnome pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtk30
GH_ACCOUNT=	jovanlanik
MAKEFILE=	makefile
LDFLAGS+=	-Wl,--as-needed # gtk30 deps
PLIST_FILES=	bin/${PORTNAME} \
		etc/pam.d/${PORTNAME} \
		share/man/man1/${PORTNAME}.1.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
