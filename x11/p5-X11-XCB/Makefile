# $FreeBSD$

PORTNAME=	X11-XCB
PORTVERSION=	0.12
CATEGORIES=	x11 perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pi@FreeBSD.org
COMMENT=	Perl bindings for libxcb

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	libxcb.so:${PORTSDIR}/x11/libxcb \
		libxcb-util.so:${PORTSDIR}/x11/xcb-util \
		libxcb-icccm.so:${PORTSDIR}/x11/xcb-util-wm
BUILD_DEPENDS=	\
		${LOCALBASE}/share/xcb/xcb.xsd:${PORTSDIR}/x11/xcb-proto \
		p5-Data-Dump>=0:${PORTSDIR}/devel/p5-Data-Dump \
		p5-Mouse>=0:${PORTSDIR}/devel/p5-Mouse \
		p5-MouseX-NativeTraits>=0:${PORTSDIR}/devel/p5-MouseX-NativeTraits \
		p5-ExtUtils-Depends>=0:${PORTSDIR}/devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Test-Deep>=0:${PORTSDIR}/devel/p5-Test-Deep \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Try-Tiny>=0:${PORTSDIR}/lang/p5-Try-Tiny \
		p5-XML-Descent>=0:${PORTSDIR}/textproc/p5-XML-Descent \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-XS-Object-Magic>=0:${PORTSDIR}/devel/p5-XS-Object-Magic
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_XORG=	x11 xcb xproto xinerama
MAKE_JOBS_UNSAFE=	yes

pre-configure:
	cd ${WRKSRC} && ${PERL} Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/X11/XCB/XCB.so

.include <bsd.port.mk>
