PORTNAME=	subtle
PORTVERSION=	0.11.3224
PORTREVISION=	1
CATEGORIES=	x11-wm ruby
MASTER_SITES=	https://subtle.subforge.org/attachments/download/81/
DISTNAME=	${PORTNAME}-${PORTVERSION}-xi

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Grid-based manual tiling window manager
WWW=		https://subtle.subforge.org/

LICENSE=	GPLv2

BUILD_DEPENDS=	rake:devel/rubygem-rake

USES=		compiler:c11 pkgconfig ruby tar:tbz2 xorg
USE_XORG=	x11 xft xinerama xpm xrandr xtst

MAKE_CMD=	rake -v
MAKEFILE=	Rakefile
ALL_TARGET=	build

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 1d ${WRKSRC}/data/subtler/runner.rb
	@${REINPLACE_CMD} -e 's,File\.exists\?,File.exist?,' \
		${WRKSRC}/data/sur/server.rb
	@${REINPLACE_CMD} -e 's,/etc/xdg,${LOCALBASE}&,' \
		${WRKSRC}/src/subtle/ruby.c
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -e '/cflags/s/-Wall/-Wall -Wno-error=incompatible-function-pointer-types /g' \
		${WRKSRC}/Rakefile
.endif


do-configure:
	@cd ${WRKSRC} && ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} config

.include <bsd.port.post.mk>
