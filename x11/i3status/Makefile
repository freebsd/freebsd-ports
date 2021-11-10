PORTNAME=	i3status
PORTVERSION=	2.14
CATEGORIES=	x11
MASTER_SITES=	http://i3wm.org/i3status/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Small program for generating a status bar

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libconfuse.so:devel/libconfuse \
		libyajl.so:devel/yajl

USES=		meson pkgconfig tar:xz perl5
MESON_ARGS=	-Dpulseaudio=false
USE_PERL5=	build

post-patch:
	@${REINPLACE_CMD} -e 's|/etc|${PREFIX}/etc|g' ${WRKSRC}/i3status.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/etc/i3status.conf \
		${STAGEDIR}${PREFIX}/etc/i3status.conf.sample

.include <bsd.port.mk>
