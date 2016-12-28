# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	subtle
PORTVERSION=	0.11.3224
CATEGORIES=	x11-wm ruby
MASTER_SITES=	http://subtle.subforge.org/attachments/download/81/
DISTNAME=	${PORTNAME}-${PORTVERSION}-xi

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Grid-based manual tiling window manager

LICENSE=	GPLv2

BUILD_DEPENDS=	rake:devel/rubygem-rake

USES=		pkgconfig shebangfix tar:tbz2
USE_RUBY=	yes
USE_XORG=	x11 xft xinerama xpm xrandr xtst

MAKE_CMD=	rake -v
MAKEFILE=	Rakefile
ALL_TARGET=	build

post-patch:
	@${REINPLACE_CMD} -e 's,/etc/xdg,${LOCALBASE}&,' \
		${WRKSRC}/src/subtle/ruby.c

do-configure:
	@cd ${WRKSRC} && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} config

.include <bsd.port.mk>
