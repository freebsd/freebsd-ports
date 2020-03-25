# $FreeBSD$

PORTNAME=	wlogout
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	x11

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Wayland-based logout menu

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgtk-layer-shell.so:x11-toolkits/gtk-layer-shell

USES=		compiler:c11 gnome meson pkgconfig
USE_GITHUB=	yes
USE_GNOME=	gtk30
GH_ACCOUNT=	ArtsyMacaw

OPTIONS_DEFINE=	MANPAGES
OPTIONS_DEFAULT=MANPAGES
OPTIONS_SUB=	yes

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc
MANPAGES_MESON_ENABLED=	man-pages

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/main.c \
		${WRKSRC}/man/${PORTNAME}.1.scd \
		${WRKSRC}/style.css

post-install:
# Let @sample handle default files under etc/
	@for f in ${STAGEDIR}${ETCDIR}/*; do \
		${MV} $$f $$f.sample; \
	done

.include <bsd.port.mk>
