PORTNAME=	X11-XCB
DISTVERSION=	0.24
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	zhmylove@narod.ru
COMMENT=	Perl bindings for libxcb
WWW=		https://metacpan.org/release/X11-XCB

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${LOCALBASE}/share/xcb/xcb.xsd:x11/xcb-proto \
		p5-Data-Dump>=0:devel/p5-Data-Dump \
		p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-XML-Descent>=0:textproc/p5-XML-Descent \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-XS-Object-Magic>=0:devel/p5-XS-Object-Magic
LIB_DEPENDS=	libxcb-icccm.so:x11/xcb-util-wm \
		libxcb-util.so:x11/xcb-util \
		libxcb.so:x11/libxcb
RUN_DEPENDS=	p5-Mouse>=0:devel/p5-Mouse \
		p5-Try-Tiny>=0:lang/p5-Try-Tiny \
		p5-XS-Object-Magic>=0:devel/p5-XS-Object-Magic
TEST_DEPENDS=	p5-Test-Deep>=0:devel/p5-Test-Deep \
		p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		localbase perl5 xorg
USE_PERL5=	configure
USE_XORG=	x11 xcb xinerama xorgproto
MAKE_JOBS_UNSAFE=	yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/X11/XCB/XCB.so

.include <bsd.port.mk>
