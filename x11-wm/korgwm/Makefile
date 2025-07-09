PORTNAME=	korgwm
DISTVERSION=	5.0
PORTREVISION=	2
CATEGORIES=	x11-wm perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ZHMYLOVE
DISTNAME=	X11-${PORTNAME}-${DISTVERSION}

MAINTAINER=	zhmylove@narod.ru
COMMENT=	Tiling window manager written in pure Perl
WWW=		https://github.com/zhmylove/korgwm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-AnyEvent>=0:devel/p5-AnyEvent \
		p5-AnyEvent-DBus>=0:devel/p5-AnyEvent-DBus \
		p5-Glib-Object-Introspection>=0:devel/p5-Glib-Object-Introspection \
		p5-Gtk3>=0:x11-toolkits/p5-Gtk3 \
		p5-X11-XCB>=0.23:x11/p5-X11-XCB \
		p5-YAML-Tiny>=0:textproc/p5-YAML-Tiny

USES=		perl5 pkgconfig xorg
USE_PERL5=	configure
USE_XORG=	xcb xinerama xrandr

NO_ARCH=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/korgwm.conf.sample ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
